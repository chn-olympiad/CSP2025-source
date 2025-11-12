#include<bits/stdc++.h>
using namespace std;
long long cnt;
string s;
const int N=1e5+55;
long long a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.size();
	//cout << n;
	if(n==1){
		cout << s[0];
		return 0;	
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			cnt++;
			a[cnt]=0;
			//cout << a[cnt++]<<endl;
		}
		if(s[i]=='1'){
			cnt++;
			a[cnt]=1;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='2'){
			cnt++;
			a[cnt]=2;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='3'){
			cnt++;
			a[cnt]=3;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='4'){
			cnt++;
			a[cnt]=4;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='5'){
			cnt++;
			a[cnt]=5;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='6'){
			cnt++;
			a[cnt]=6;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='7'){
			cnt++;
			a[cnt]=7;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='8'){
			cnt++;
			a[cnt]=8;
			//cout << a[cnt]<<endl;
		}
		if(s[i]=='9'){
			cnt++;
			a[cnt]=9;
			//cout << a[cnt]<<endl;
		}
	}
	
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout << a[i];
   	}
	return 0;
}

