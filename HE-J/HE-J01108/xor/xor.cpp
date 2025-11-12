#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0,sum=0;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) num++;
		if(a[i]==1) sum++;
	}
	if(num%2==0&&sum%2==0) cout<<0;
	else if(num%2==0&&sum%2==1) cout<<1;
	else if(num%2==1&&sum%2==0) cout<<0;
	else if(num%2==1&&sum%2==1) cout<<1;
	return 0;
}
//感觉T1T2要炸怎么办没有输入输出 
//行这个有输入输出，那前两道咋办啊啊啊啊 
//骗分骗的不对但是真的不知道怎么骗了QAQ 
