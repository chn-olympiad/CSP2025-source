#include<bits/stdc++.h>
using namespace std;
int n,a[1005],m,sum[100005],k,cnt,t;
int check(int left,int right){
	int t=0;
	t=a[left]^a[left+1];	
	for(int i=left+2;i<=right;i++){
			t=t^a[i];
	}return t;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
}int left=1;
int right=1;
int t;
while(right<=n){
	if(left==right){
		t=a[right];
	}
	else t=check(left,right);
	cout<<t<<endl;
	if(t==k){
		cnt++;
		int lon=right-left+1;
		left+=lon;
		right+=lon;
	}else{
			right++;
		}
}cout<<cnt;
fclose(stdin);
fclose(stdout);
	return 0;
}
