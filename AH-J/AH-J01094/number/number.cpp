#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("nunber.out","w",stdout);
    string s;
    cin>>s;
    int k=s.length();
    int a[k];
    int maxn=0;
    int l=0;
    int n=0;
    int f=0;
    int t=0;
    int r=0;
    
    for(int i=0;i<k;i++){
		a[i]=0;
	}
	for(int i=0;i<k;i++){
		if(s[i]-'a'>=0){
			continue;
		}else{
			a[t]=s[i]-'0';
			t++;
		}
	}
	for(int j=0;j<k;j++){
	    for(int i=r;i<k;i++){
		    if(a[i]>maxn){
		    	maxn=a[i];
		    	l=i;
		    }
		}
		r++;
		n=a[f];
		a[f]=a[l];
		a[l]=n;
		f+=1;
		maxn=0;
	}
    for(int i=0;i<t;i++){
		cout << a[i] <<" ";
	}
    return 0;
}
