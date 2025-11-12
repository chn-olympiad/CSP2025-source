#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int l[N];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.ans","w",stdout);
	int n;
	cin>>n;
	int cnt;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	int f,s;
	for(int i=2;i<n;i++){
	   	s=l[i-1];
	   	f=l[i-2];
		if(s+f>l[i]){
			while(s+f<=l[i]){
				if(f!=0) f--;
				else s--;
				cnt++;
		    }
		}
	}
	cout<<cnt;
	return 0;
}