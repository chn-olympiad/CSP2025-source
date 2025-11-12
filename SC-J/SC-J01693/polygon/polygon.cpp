#include<bits/stdc++.h>
using namespace std;
int n;

int a[10001];


string s[10001];

int si=1;
bool check(string s1){
	for(int i=1;i<=si;i++){
		if(s1==s[i]){
			
			
			return 0;
		}
		
	}
	return 1;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string s1="";
	int sum=0;
	int ma=0;
	int m=0;
	for(int i=1;i<=n;i++){
		
		sum=a[i];
		for(int x=i+1;x<=n;x++){
			char xx=(a[i]+'0');
		    m=1;s1=xx;
			for(int j=x;j<=n;j++){
				sum+=a[j];
				char c=(a[j]+'0');
				s1=s1+c;
				m++;
				if(sum>2*a[j]&&m>=3&&check(s1)){
					s[si]=s1;
					si++;
					ma++;
				}
			}
		}
	}
	cout<<ma%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}