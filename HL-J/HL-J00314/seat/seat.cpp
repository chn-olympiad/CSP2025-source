#include <bits/stdc++.h>
using namespace std;
#define int long long 
int score[500];
int n,m,num;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int x=score[1];
	sort(score+1,score+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==x) num=i;
	}
	int r=num/n;
	if(num%n!=0) r++;
	int l=num%n;
	if(l==0) l=n;
	if(!(r&1)) l=n-l+1;
	cout<<r<<' '<<l<<endl;
	return 0;
}
