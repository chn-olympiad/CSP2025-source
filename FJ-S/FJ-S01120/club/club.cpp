#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int v,id;
}a[N][3];
ll ans;
int n,t,cnt[3],b[N],bc;
void in(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++){
			cin>>a[i][j].v;
			a[i][j].id=j;
		}			
	for(int i=0;i<3;i++)
		cnt[i]=0; 
	for(int i=1;i<=n;i++)
		b[i]=0;
	ans=0;bc=0;	
}
int cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		in();
		for(int i=1;i<=n;i++){
			sort(a[i],a[i]+3,cmp);
			ans+=a[i][0].v;
			cnt[a[i][0].id]++;			
		}
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2){
				for(int j=1;j<=n;j++)
					if(a[j][0].id==i)
						b[++bc]=a[j][0].v-a[j][1].v;
				sort(b+1,b+bc+1);
				for(int j=1;j<=cnt[i]-(n/2);j++)
					ans-=b[j];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
