#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool cmp(int x,int y){return x>y;} // descend sort
struct stu{
	int val[5],tmp[5];
	void init(){for(int i=1;i<=3;i++) tmp[i]=val[i];sort(tmp+1,tmp+4,cmp);}
	int mv(int num){return tmp[num];}
	int mn(int num){for(int i=1;i<=3;i++) if(tmp[num]==val[i]) return i;}
}a[N];
int t,n;
int us[5],ans=0; // search
void dfs(int cur,int sum){
	if(cur==n+1) ans=max(ans,sum);
	for(int i=1;i<=3;i++){
		if(us[i]+1<=n/2) {
			us[i]++;
			dfs(cur+1,sum+a[cur].val[i]);
			us[i]--;
		}
	}
}
bool is_A=1,is_B=1;
bool cmp2(stu x,stu y){
	return x.val[1]>y.val[1];
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) {
    	//input
    	cin>>n;
    	memset(a,0,sizeof(a));
		is_A=1,is_B=1;
    	for(int i=1;i<=n;i++) {
		    for(int j=1;j<=3;j++) cin>>a[i].val[j];
		    if(a[i].val[3]!=0) is_A=0,is_B=0;
		    if(a[i].val[2]!=0) is_A=0;
		    a[i].init();
		}
    	if(n==2){
    		if(a[1].mn(1)!=a[2].mn(1)) {cout<<a[1].mv(1)+a[2].mv(1)<<"\n";}
			else{cout<<max(a[1].mv(1)+a[2].mv(2),a[1].mv(2)+a[2].mv(1))<<"\n";}
		}
		else if(n==4||n==10||n==30){
			memset(us,0,sizeof(us));
			ans=0;
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else if(is_A){ // No.12
		    int sum=0;
		    sort(a+1,a+n+1,cmp2);
		    for(int i=1;i<=n/2;i++) sum+=a[i].val[1];
		    cout<<sum<<"\n";
		}
		else if(is_B){
			priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
			int s=0;
			for(int i=1;i<=n;i++) a[i].val[3]=-1,a[i].init();
			for(int i=1;i<=n;i++) q[a[i].mn(1)].push(make_pair(a[i].mv(1)-a[i].mv(2),i));
			if(q[1].size()>n/2) {
				while(q[1].size()>n/2) {
					q[2].push(q[1].top());
					q[1].pop(); 
				}
			}
			else if(q[2].size()>n/2) {
				while(q[2].size()>n/2) {
					q[1].push(q[2].top());
					q[2].pop(); 
				}
			}
			for(int i=1;i<=2;i++){
				while(!q[i].empty()) {
					int no=q[i].top().second;
					s+=a[no].val[i];
					q[i].pop();
				}
			}
			cout<<s<<"\n";
		}
	}
	return 0;
}

