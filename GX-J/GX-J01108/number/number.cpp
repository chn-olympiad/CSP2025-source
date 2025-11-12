#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],c,d[1000000];
int t,m,n;
string s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	c=s1.size();
	for(int i=0;i<c;i++){
		if(s1[i]<='9'&&s1[i]>='0'){
			b[t]=true;
//		cout<<s1[i]<<endl;
			a[t]=s1[i]-48;
			t++;
		}
	}
//	cout<<"t="<<t<<endl;
	for(int i=0;i<t;i++){
			m=0;
			n=0;
		for(int j=0;j<t;j++){
			if(j==i);
			else{
//				cout<<"a[i]"<<a[i]<<"a[j]"<<a[j]<<endl;
				if(a[i]<a[j]){
					m++;
//					cout<<m<<"   mm"<<endl;
					} 
				if(a[i]==a[j])n++;
			}
		}
		d[m]=a[i];
//		cout<<"m="<<m<<" a="<<a[i]<<"  d="<<d[m]<<endl;
		if(n!=0){
			for(int j=1;j<=n;j++){
				d[m+j]=a[i];
			}
		}
	}
//	cout<<endl;
	for(int i=0;i<t;i++){
			cout<<d[i];
		}
	return 0;
}
