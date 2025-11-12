#include <iostream>
#include <string>
using namespace std;
long long suber(string s,char x){
	for(long long i=0;i<s.size();i++){
		if(s[i]==x)return i;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,arr[10000000][3]={},num=0;
	cin>>n>>q;
	for(long long u=0;u<n;u++){
		string h,k;
		cin>>h>>k;
		long long a=suber(h,'b'),b=suber(k,'b');
		arr[u][0]=a-b;
		arr[u][1]=a;
		arr[u][2]=h.size()-b-1;
	}
	for(int i=0;i<q;i++){
		num=0;
		string h,k;
		cin>>h>>k;
		long long a=suber(h,'b')-suber(k,'b'),b=suber(h,'b'),c=h.size()-suber(h,'b')-1;
		for(long long j=0;j<n;j++){
			if(arr[j][0]==a&&b>=arr[j][1]&&c>=arr[j][2])num++;
		}
		cout<<num<<endl;
	}
}
