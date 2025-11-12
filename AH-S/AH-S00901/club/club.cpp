#include<bits/stdc++.h>
using namespace std;
int temp;
int T;
struct node{
	int a1,a2,a3;
	int ans,id;
}a[100005];
int ans1,ans2,ans3;
int n;
int maxx;
bool cmp(node x,node y){
	return x.ans<y.ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans1=ans2=ans3=temp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
			int minn=min(a[i].a1,min(a[i].a2,a[i].a3));
			if(a[i].a1==maxx){
				ans1++;
				a[i].id=1;
			}
			else if(a[i].a2==maxx){
				ans2++;
				a[i].id=2;
			}
			else if(a[i].a3==maxx){
				ans3++;
				a[i].id=3;
			}
			temp+=maxx;
			a[i].ans=maxx-(a[i].a1+a[i].a2+a[i].a3-maxx-minn);
		}
		if(ans1>n/2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;ans1>n/2;i++){
				if(a[i].id==1){
					temp-=a[i].ans;
					ans1--;
				}
			}
		}
		if(ans2>n/2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;ans2>n/2;i++){
				if(a[i].id==2){
					temp-=a[i].ans;
					ans2--;
				}
			}
		}if(ans3>n/2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;ans3>n/2;i++){
				if(a[i].id==3){
					temp-=a[i].ans;
					ans3--;
				}
			}
		}
		cout<<temp<<endl;
		
	}
}
