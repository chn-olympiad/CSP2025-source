#include<bits/stdc++.h>

using namespace std;
const int  N=1e6+10; 
string s,a[N];
int tot; 
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s>="0"&&s<="9"){
			a[i++]=s;
			tot++;
			sort(a+1,a+tot);
		}
	}

	for(int i=0;i<tot;i++){
		cout<<a[i];
	}
	return 0;
} 