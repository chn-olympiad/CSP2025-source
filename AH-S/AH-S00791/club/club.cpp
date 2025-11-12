#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int a[100005][3],v[100005],r[100005];
typedef pair<int,int> p;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		priority_queue<p> q;
		int n,ans=0,s[3]={0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];v[i]=0;s[0]++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];v[i]=1;s[1]++;
			}
			else{
				ans+=a[i][2];v[i]=2;s[2]++;
			}
		}
		if(s[0]<=n/2&&s[1]<=n/2&&s[2]<=n/2){
			printf("%d\n",ans);
			continue;
		}
		for(int i=0;i<=2;i++){
			if(s[i]<=n/2)continue;
			for(int j=1;j<=n;j++){
				if(v[j]==i)v[j]=0;
				else if(v[j]==0)v[j]=i;
				int u=a[j][i];a[j][i]=a[j][0];a[j][0]=u;
			//	u=v[0];v[0]=v[j];v[j]=u;
			}
			int uu=s[i];s[i]=s[0];s[0]=uu;
			break;
		}
		//for(int i=1;i<=n;i++){
	//		for(int j=0;j<=2;j++)
		//		printf("%d ",a[i][j]);
	//		printf("\n");
//		}
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				q.push(make_pair(a[i][1]-a[i][0],i));
				q.push(make_pair(a[i][2]-a[i][0],i));
			}
		}
		int ch=s[0]-n/2;
	//	cout<<ch<<" ";
	//	cout<<q.size();
		while(ch){
			p h=q.top();
			q.pop();
			if(r[h.second])continue;
			r[h.second]=1;
			ans=ans+h.first;
			ch--;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)r[i]=0;
	}
	return 0;
}
