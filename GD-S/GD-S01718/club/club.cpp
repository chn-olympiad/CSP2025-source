#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int T,n,a[N][4],cnt[4],s[N];
vector<int> c1,c2,c3;
int getnxt(int i){
	if(a[i][1]>=a[i][2]){
		if(a[i][1]>=a[i][3]) {
			if(a[i][2]>=a[i][3]) {
				return 2;
			}
			else return 3;
		}
		else return 1;
	}
	else {
		if(a[i][2]>=a[i][3]) {
			if(a[i][1]>=a[i][3]) return 1;
			else return 3;
		}
		else return 2;
	}
}
void work(){
	scanf("%d",&n);
	int ans = 0;
	c1.clear(); c2.clear(); c3.clear();
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]){
			if(a[i][1]>=a[i][3]) c1.push_back(i),ans+=a[i][1];
			else c3.push_back(i),ans+=a[i][3];
		}
		else {
			if(a[i][2]>=a[i][3]) c2.push_back(i),ans+=a[i][2];
			else c3.push_back(i),ans+=a[i][3];
		}
	}
	int len1 = c1.size();
	int len2 = c2.size();
	int len3 = c3.size();
	if(len1>n/2){
		for(int i=0;i<len1;i++){
			s[i] = a[c1[i]][1]-a[c1[i]][getnxt(c1[i])];
			
		}
		sort(s,s+len1);
		for(int i=0;i<(len1-n/2);i++) ans -= s[i];
	}
	else if(len2>n/2){
		for(int i=0;i<len2;i++){
			s[i] = a[c2[i]][2]-a[c2[i]][getnxt(c2[i])];
//			if(T==3)cout<<"c2="<<c2[i]<<" "<<getnxt(c2[i])<<endl;
		}
		sort(s,s+len2);
		for(int i=0;i<(len2-n/2);i++) ans -= s[i];
	}
	else if(len3>n/2){
		for(int i=0;i<len3;i++){
			s[i] = a[c3[i]][3]-a[c3[i]][getnxt(c3[i])];
		}
		sort(s,s+len3);
		for(int i=0;i<(len3-n/2);i++) ans -= s[i];
	}
	printf("%d\n",ans);
}
int main(){
//	a[1][1]=2; a[1][2]=3; a[1][3]=0;
//	cout<<getnxt(1);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		work();
	}
	return 0;
} 
