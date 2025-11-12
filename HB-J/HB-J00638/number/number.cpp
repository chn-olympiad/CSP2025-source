# include <bits/stdc++.h>
using namespace std;
long long l[1000050];
string s;
void f(int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(l[j]<l[j+1]){
				int temp=l[j];
				l[j]=l[j+1];
				l[j+1]=temp;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);
	getline(cin,s);
	long long n=s.size();
	long long j=0;
	char temp;
	for(long long i=0;i<n;i++){
		temp=s[i];
		if(temp>='0' && temp<='9') {l[j]=int(temp)-48;j++;}
	}
	f(j);
	for(long long i=0;i<j;i++){
		cout<<l[i];
	}
	cout<<endl;
	return 0;
}
