#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	if(a!=b) {
		return a>b;
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,place,temp;
	cin>>n>>m;
	int s=m*n;
	int people[114514];
	for(int i=1; i<=s; i++) {
		cin>>people[i];
		temp=people[1];
	}
	sort(people+1,people+1+s,cmp);
	for(int i=1; i<=s; i++) {
		if(temp==people[i]) {
			place=i;
		}
		//cout<<people[i]<<" ";
	}
	//cout<<place;
	if(place<=n) {
		cout<<1<<" "<<place;
		return 0;
	}else if ((place-place%n)/n+1>m&&place==s&&m==n){
		cout<<m<<n;
		return 0;
	}else if(((place-place%n)/n)%2==0) {
		cout<<(place-place%n)/n+1<<" "<<place%n;
		return 0;
	} else {
		cout<<(place-place%n)/n+1<<" "<<n-place%n+1;
		return 0;
	}
}
