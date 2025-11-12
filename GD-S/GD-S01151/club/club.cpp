#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,m[100005][3],max1[3],max2,j1,i1;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	cin>>t;
	for(int v=0;v<t;v++){
		ans=0;
		for(int j=0;j<n;j++){
			for(int q=0;q<3;q++){
				m[j][q]=0;
			}
		}
		cin>>n;
		for(int j=0;j<n;j++){
			for(int q=0;q<3;q++){
				cin>>m[j][q];
			}
		}
		for(int i=0;i<3;i++){
			max1[i]=(n/2);
		}
		for(int j=0;j<n;j++){
			for(int i=0;i<3;i++){
				if(max1[i]==0){
					for(int k=0;k<n;k++){
						m[k][i]=0;
					}
				}
			}
		max2=0,i1=0,j1=0;
		for(int i=0;i<n;i++){
			for(int b=0;b<3;b++){
				if(m[i][b]>max2){
					i1=i;
					j1=b;
				}
			max2=max(max2,m[i][b]);
			}
		}
			max1[j1]--;
			m[i1][0]=0,m[i1][1]=0,m[i1][2]=0;
			ans+=max2;
		}
		cout<<ans<<endl;
	}
	freopen("club.ans","w",stdout);
}

