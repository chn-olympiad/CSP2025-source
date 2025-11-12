#include<bits/stdc++.h>
using namespace std;

const int MAXN=110;
int n,m;
int a[MAXN];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>a[1];
	int sum=n*m,now=a[1];
	for(int i=2;i<=sum;i++) cin>>a[i];
	sort(a+1,a+sum+1,cmp);
	
	int cnt=-1;
	for(int i=1;i<=sum;i++){
		if(a[i]==now){
			cnt=i;
			break;
		}
	}
	
	int h=cnt/n,l=cnt%n;
	if(l) h++;
	else l=n;
	if((h&1)==0){
		//偶数行从后往前数
		l=n-l+1;
	}
	cout<<h<<" "<<l<<"\n";
	return 0;
}