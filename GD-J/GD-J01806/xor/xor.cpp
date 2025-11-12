#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,ans=0;
struct node{
	int num,vis=1,win=1;
}a[N];
int check(int i,int j){
	int cnt=0,remember;
	for(int l=i;l<=j;l++){
		if(a[l].vis!=0 && a[l].win!=0){
			cnt=a[l].num;
			remember=l;
		}
	}
	if(cnt==0)return -1;
	for(int l=i;l<=j;l++){
		if(a[l].vis==1 && a[l].win!=0 && remember!=l){
			cnt=(cnt xor a[l].num);
			a[l].vis=0;
		}
	}
	return cnt;
}
void bru(int i,int j){
	for(int l=i;l<=j;l++){
		a[l].vis=1;
	}
	return ;
}
void per(int i,int j){
	for(int l=i;l<=j;l++){
		a[l].win=0;
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i].num;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)==k){
				ans++;
				per(i,j);
			}
			else{
				bru(i,j);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
