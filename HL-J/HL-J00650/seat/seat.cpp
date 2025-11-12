#include <bits/stdc++.h>
using namespace std;
int a,b,s[110],x=0,w=0,h=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>s[i];
	}
	int cnt=s[1];

	for(int i=1;i<a*b;i++){
		if(s[i]<s[i+1]){
			x=s[i];
			s[i]=s[i+1];
			s[i+1]=x;
		}
	}	
	
	for(int i=1;i<=a*b;i++){
		if(s[i]==cnt){
		w=i;
			break;
		}
	}
	int q=w/a;
	if(w%a!=0)
	q++;
	int p=w-(q-1)*a;
    if(q%2==0){
    	h=a-p;
    	h=a-h+1;
    	if(h==0)
    	h=1;
	}
	else
	   h=p;
	cout<<q<<" "<<h;
	return 0;
}
