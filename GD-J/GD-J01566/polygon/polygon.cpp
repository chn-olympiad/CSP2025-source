#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
long long tall=0;
int n;
int num[5500];
void find(int pos,int sum,int cnt){
	if(pos==n+1) return;
	//y
	sum+=num[pos];
	cnt++;
	if(cnt>=3){
		int tmp=2;
		if(sum>2*num[pos]) tall++;
	}
	find(pos+1,sum,cnt+1);
	//n
	sum-=num[pos];
	cnt--;
	find(pos+1,sum,cnt); 
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1,cmp);
	int pos=1;
	long long all=0;
	long long sum=0;
	int tmax;
	int cnt=0;
	find(1,0,0);
	cout<<tall;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
