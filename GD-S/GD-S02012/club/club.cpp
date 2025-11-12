#include<bits/stdc++.h>
using namespace std;
int a[100105][3],n,b1,b2,b3,t,p[20105];//,f[31][3376],f[300][200][200][200]
int dfs(int i){
	int m=INT_MIN;
	//if(f[i][b1*225+b2*15+b3]) return f[i][b1*225+b2*15+b3];
	if(i==n){
		if(b1!=0){
			m=max(m,a[i][0]);
		}
		if(b2!=0){
			m=max(m,a[i][1]);
		}
		if(b3!=0){
			m=max(m,a[i][2]);
		}
		return m;
	}
	if(b1!=0){
		b1--;
		m=max(m,a[i][0]+dfs(i+1));
		b1++;
	}
	if(b2!=0){
		b2--;
		m=max(m,a[i][1]+dfs(i+1));
		b2++;
	}
	if(b3!=0){
		b3--;
		m=max(m,a[i][2]+dfs(i+1));
		b3++;
	}
	return m;//f[i][b1*225+b2*15+b3]=
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		int tp2=1,tp3=1; 
		b1=n/2;
		b2=b1;
		b3=b2;
		for(int i=1;i<=n;i++){
			cin>>a[i][0];
			cin>>a[i][1];if(a[i][1])tp2=0;
			cin>>a[i][2];if(a[i][2])tp3=0;
		}
		if(tp2&&tp3){
			for(int i=1;i<=n;i++){
				++p[a[i][0]];
			}
			int ans=0;
			for(int i=20000;b1>0;i--){
				if(p[i]){
					ans+=i*min(b1,p[i]);
					b1-=min(b1,p[i]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<dfs(1)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
