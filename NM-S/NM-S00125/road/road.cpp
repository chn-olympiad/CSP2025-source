#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int m_1[500005],m_2[500005],m_3[500005],m_4,m_5;
	int m_6=0;
	int k_1[500005],k_2[500005][500005],k_3,k_4;
	int k_5[500005];
	int l_1,l_2;
	for(int i=1;i<=m;++i){
		cin >> m_1[i] >> m_2[i] >> m_3[i];
		if(i==1){
			m_4=m_3[i];
		}
		else if(i==2){
			m_5=m_3[i];
		}
		else{
			if(m_3[1]<m_3[2]){
				if(m_3[i]<m_3[2]){
					m_3[2]=m_3[i];
				}
				m_4=m_3[2];
			}
			else{
				if(m_3[i]<m_3[1]){
					m_3[1]=m_3[i];
				}
				m_5=m_3[1];	
			}	
		}
	}
	m_6+=m_4;
	m_6+=m_5;
	for(int i=1;i<=k;++i){
		cin >> k_1[i];
		for(int j=1;j<=n;++j){
			cin >> k_2[i][j];
			if(j==1){
				k_3=k_2[i][1];
			}
			else if(j==2){
				k_4=k_2[i][2];
			}
			else{
				if(k_2[i][1]<k_2[i][2]){
					if(k_2[i][j]<k_2[i][2]){
						k_2[i][2]=k_2[i][j];
					}
					k_3=k_2[i][2];
				}
				else{
					if(k_2[i][j]<k_2[i][1]){
						k_2[i][1]=k_2[i][j];
					}					
					k_4=k_2[i][1];
				}
			}
		}
		k_5[i]+=k_3;
		k_5[i]+=k_4;
		k_5[i]+=k_1[i];
	}
	for(int i=1;i<=k;++i){
		if(i==1){
			l_1=k_5[1];
		}
		else{
			if(k_5[i]<k_5[1]){
				l_1=k_5[i];
			}
		}
	}
	l_2=m_6+l_1;
	cout << l_2;
	return 0;
}
