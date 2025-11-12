#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct node{
	long long v,id1,id2,id3;
};
int a1[N],a2[N],a3[N];node f[N][5];
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(f[i-1][j].id1<(n/2)){
				if(f[i][1].v<f[i-1][j].v+a1[i]){
					f[i][1].id1=f[i-1][j].id1+1;
					f[i][1].v=f[i-1][j].v+a1[i];
					//cout<<"di"<<i<<"yuangong xuan "<<j<<"ci zhuan yi de dao"<<f[i][1].v<<" "<<f[i][1].id1<<" 111";
				}
				
			}
			cout<<endl;
			if(f[i-1][j].id2<(n/2)){
				if(f[i][2].v<f[i-1][j].v+a2[i]){
					f[i][2].id2=f[i-1][j].id2+1;
					f[i][2].v=f[i-1][j].v+a2[i];
					//cout<<"di"<<i<<"yuangong xuan "<<j<<"ci zhuan yi de dao"<<f[i][2].v<<" "<<f[i][2].id2<<" 2222";
				}
				
			}
			cout<<endl;
			if(f[i-1][j].id3<(n/2)){
				if(f[i][3].v<f[i-1][j].v+a3[i]){
					f[i][3].id3=f[i-1][j].id3+1;
					f[i][3].v=f[i-1][j].v+a3[i];
					//cout<<"di"<<i<<"yuangong xuan "<<j<<"ci zhuan yi de dao"<<f[i][3].v<<" "<<f[i][3].id3<<" 3333";
				}
				
			}
			cout<<endl;
		}
		}
		cout<<max(f[n][1].v,max(f[n][2].v,f[n][3].v))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}