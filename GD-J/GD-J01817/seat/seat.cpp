#include<bits/stdc++.h>
using namespace std;
void fre(){
	 freopen("seat.in","r",stdin);
	 freopen("seat.out","w",stdout);
}
int n,m;
int a[110];
int main(){
	fre();
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int score=a[1],pos;
	sort(a+1,a+c+1,greater<int>());
	for(int i=1;i<=c;i++){
		if(a[i]==score){
			pos=i;
			break;
		}
	}
	int pn=pos/n;
	if(pos!=pn*n)pn++;
	cout<<pn<<" ";
	if(pn%2==1)cout<<pn%n+1;
	else cout<<m-pn%n;
	cout<<endl;
	return 0;
}
//100pts

