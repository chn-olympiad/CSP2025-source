#include <bits/stdc++.h>
using namespace std;
struct node{
	int x[4];
};
node num[100005];
node f[100005],top;
int find(node m,int i) {
	if (i==1) return max(m.x[1],max(m.x[2],m.x[3]));
	if (i==2) return m.x[1]+m.x[2]+m.x[3]-find(m,1)-find(m,3);
	if (i==3) return min(m.x[1],min(m.x[2],m.x[3]));
	return 0;
}
int place(node m,int i) {
	for (int k=1;k<=3;k++) {
		if (i==k) {
			for (int j=1;j<=3;j++) {
				if (find(m,k)==m.x[j]) return j;
			}
		}
	}
	return 0;
}
int cmp(node x,node y) {
	return find(x,1)-find(x,2)>find(y,1)-find(y,2);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//int ansdsb[5];
	int T;
	cin>>T;
	for (int dsb=0;dsb<T;dsb++) {
		int n;cin>>n;
		memset(num,0,sizeof(num));
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&num[i].x[1],&num[i].x[2],&num[i].x[3]);
		}
		long long ans=0;
		//int top=1;
		sort(num+1,num+n+1,cmp);
		int k[4]={114514,0,0,0};
		for (int i=1;i<=n;i++) {
			if (k[place(num[i],1)]>=n/2) {
				ans+=find(num[i],2);
			}
			else {
				ans+=find(num[i],1);
				k[place(num[i],1)]++;
			}
		}//成功选上第一志愿，接下来的都是第一志愿已满，故分配第二志愿
		cout<<ans<<'\n';
		//ansdsb[dsb]=ans;
	}
	/*
	for (int i=0;i<T;i++) {
		cout<<ansdsb[i]<<endl;
	}
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
