#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[100005],b[100005],c[100005];
int t;
long long ans=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i]>>c[i];
		int ca=0,cb=0,cc=0;
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		int half=n/2;
		for(int i=0;i<n;i++){
			int aa=a[i],ba=b[i];
			if(aa>=ba){
				if(ca<=half){
					ca++;
					ans+=aa;
				}
				else{
					cb++;
					ans+=ba;
				}
			}
			else{
				if(cb<=half){
					cb++;
					ans+=ba;
				}
				else{
					ca++;
					ans+=aa;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
