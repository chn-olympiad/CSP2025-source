#include<bits/stdc++.h>
using namespace std;
long long a,s[10000005],q[10000][10000],w,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	sort(s+1,s+a+1);
	for(int i=3;i<=a;i++){
		for(int j=i;j<=a;j++){
			w=0;
			
			for(int k=j-i+1;k<=j;k++){
				w+=s[k];
			}
			cout<<s[j]*2<<" "<<w<<" "<<i<<endl;
			if(s[j]*2<w){
				
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
