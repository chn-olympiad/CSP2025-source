#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[205];
void solve1(int s,int t){
	if(s%m==0){
		cout<<s/m<<' '<<n;
		return;
	}
	if((s/m+1)%2!=0){
		cout<<s/m+1<<' '<<s%m;
		return;
	}
	else{
		cout<<s/m+1<<' '<<m-s%m+1;
		return;
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int temp=n*m;
	for(int i=0;i<temp;i++){
		cin>>num[i];
	}
	int r=num[0];
	sort(num,num+n*m,cmp);
	int a=0;
	while(1){
		if(num[a]==r){
			break;
		}
		a++;
	}
	a++;
	solve1(a,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
