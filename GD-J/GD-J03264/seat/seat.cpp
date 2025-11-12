#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e2+10;

struct student{
	int a,id;
}s[MAXN];

int n,m,idx;

bool cmp(student x,student y){
	return x.a>y.a;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	int sum=n*m;
	for (int i=1;i<=sum;i++){
		cin >>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+sum+1,cmp);
	for (int i=1;i<=sum;i++){
		if (s[i].id==1){
			idx=i;
			break;
		}
	}
	int x=(idx+n-1)/n,y=idx-n*(x-1);
	cout <<x <<' ';
	if (x%2) cout <<y <<'\n';
	else cout <<n-y+1 <<'\n';
	return 0;
}
