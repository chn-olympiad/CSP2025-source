#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1e5+10;
int cnt1=0,cnt2=0,cnt3=0;
struct node{
	int mem,infl;
}join1[MAXN];
struct node2{
	int mem,infl;
}join2[MAXN];
struct node3{
	int mem,infl;
}join3[MAXN];
bool cmp1(node A,node B){
	return A.infl<=B.infl;
}
bool cmp2(node2 A,node2 B){
	return A.infl<=B.infl;
}
bool cmp3(node3 A,node3 B){
	return A.infl<=B.infl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,sum=0;
	cin>>t;
	while(t--){
		sum=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				cnt1++;
				join1[cnt1].mem=i;
				join1[cnt1].infl=a-max(b,c);
				sum+=a;
			}
			if(b>=a&&b>=c){
				cnt2++;
				join2[cnt2].mem=i;
				join2[cnt2].infl=b-max(a,c);
				sum+=b;
			}
			if(c>=b&&c>=a){
				cnt3++;
				join3[cnt3].mem=i;
				join3[cnt3].infl=c-max(b,a);
				sum+=c;
			}
		}
		sort(join1+1,join1+1+cnt1,cmp1);
		sort(join2+1,join2+1+cnt2,cmp2);
		sort(join3+1,join3+1+cnt3,cmp3);
		if(cnt1>n/2){
			for(int s=1;s<=cnt1-n/2;s++){
				sum-=join1[s].infl;
			}
		}
		else if(cnt2>n/2){
			for(int s=1;s<=cnt2-n/2;s++){
				sum-=join2[s].infl;
			}
		}
		else if(cnt3>n/2){
			for(int s=1;s<=cnt3-n/2;s++){
				sum-=join3[s].infl;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
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
