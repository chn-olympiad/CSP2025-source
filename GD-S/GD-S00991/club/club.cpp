#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

struct node{
	int to,dj;
	bool operator<(const node &x)const{
		return x.dj<dj;
	}
};
priority_queue<node>q[4];
int T,n,a[100001][4];
int gt(int x){
	if(x>3)x-=3;
	return x;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
//	freopen("club5.in","r",stdin);
//	freopen("club5.out","w",stdout); 
	cin>>T;
	for(int iiii=1;iiii<=T;iiii++){
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int cnt[4]={0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			for(int to=1;to<=3;to++){
				if(a[i][to]>=a[i][gt(to+1)]&&a[i][to]>=a[i][gt(to+2)]){
					int scd;//,rub;
					if(a[i][gt(to+1)]>a[i][gt(to+2)]){
						scd=gt(to+1);
//						rub=gt(to+2);
					}else{
						scd=gt(to+2);
//						rub=gt(to+1);
					}
					if(cnt[to]<n/2){
						cnt[to]++;
						ans+=a[i][to];
						q[to].push({scd,a[i][to]-a[i][scd]});
					}else{
						if(q[to].top().dj<a[i][to]-a[i][scd]){
							node t=q[to].top();
							q[to].pop();
							q[to].push({scd,a[i][to]-a[i][scd]});
							q[t.to].push({t.to,t.dj});
							cnt[t.to]++;
							ans=ans+a[i][to]-t.dj;
						}else{
							cnt[scd]++;
							q[scd].push({scd,a[i][scd]-a[i][to]});
							ans+=a[i][scd];
						}
					}
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	akioi;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
