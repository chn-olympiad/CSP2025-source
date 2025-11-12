#include <bits/stdc++.h>
using namespace std;
int T,n,Max,s[100005][5],s1[5];
void dg(int now,int sum){
	if(s1[0]>n/2||s1[1]>n/2||s1[2]>n/2){
		return;
	}
	if(now>=n){
		Max=max(Max,sum);
		return;
	}
	for(int i=0;i<3;i++){
		s1[i]++;
		dg(now+1,sum+s[now][i]);
		s1[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
		Max=0;
		dg(0,0);
		cout<<Max<<endl;
	}
	return 0;
}
//ÒÀ¾ÉÊ·É½¶ÑÆö 55
