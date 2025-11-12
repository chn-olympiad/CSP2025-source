#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int a[100010],b[100010],c[100010],num[3];
struct node{
	int lst,znd,zndd;
	bool operator < (const node &x)const{
		return (lst-znd)<(x.lst-x.znd);
	}
}lsta[100010],lstb[100010],lstc[100010];
void solve(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(num,0,sizeof num);
	memset(lsta,0,sizeof lsta);
	memset(lstb,0,sizeof lstb);
	memset(lstc,0,sizeof lstc);
	int n,sum=0,ant=0,bnt=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int lstt;
		if(a[i]>=b[i]){
			if(a[i]>=c[i]){
				lstt=0;
				lsta[ant].lst=a[i];
				if(b[i]>=c[i]){
					lsta[ant].znd=b[i];
					lsta[ant++].zndd=1;
				}else{
					lsta[ant].znd=c[i];
					lsta[ant++].zndd=2;
				}
			}else{
				lstt=2;
				lstc[cnt].lst=c[i];
				lstc[cnt].znd=a[i];
				lstc[cnt++].zndd=0;
			}
		}else{
			if(b[i]>=c[i]){
				lstt=1;
				lstb[bnt].lst=b[i];
				if(a[i]>=c[i]){
					lstb[bnt].znd=a[i];
					lstb[bnt++].zndd=0;
				}else{
					lstb[bnt].znd=c[i];
					lstb[bnt++].zndd=2;
				}
			}else{
				lstt=2;
				lstc[cnt].lst=c[i];
				lstc[cnt].znd=b[i];
				lstc[cnt++].zndd=1;
			}
		}
		if(lstt==0){
			sum+=lsta[ant-1].lst;
			num[lstt]++;
			if(num[lstt]>n/2){
				sort(lsta,lsta+ant);
				sum+=lsta[0].znd-lsta[0].lst;
				num[lstt]--;
				num[lsta[0].zndd]++;
			}
		}
		if(lstt==1){
			sum+=lstb[bnt-1].lst;
			num[lstt]++;
			if(num[lstt]>n/2){
				sort(lstb,lstb+bnt);
				sum+=lstb[0].znd-lstb[0].lst;
				num[lstt]--;
				num[lstb[0].zndd]++;
			}
		}
		if(lstt==2){
			sum+=lstc[cnt-1].lst;
			num[lstt]++;
			if(num[lstt]>n/2){
				sort(lstc,lstc+cnt);
				sum+=lstc[0].znd-lstc[0].lst;
				num[lstt]--;
				num[lstc[0].zndd]++;
			}
		}
	}
	cout<<sum<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 