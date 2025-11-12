#include<bits/stdc++.h>
using namespace std; 
string s,r;
int a[1000010];
int res,x=1,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=s.size();
    if(c==1)cout<<s;
else{
	for(int i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			r[i]=s[i];
			n++;
		} 
	}
	for(int i=0;i<n;i++){
		a[i]=(int)r[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
//	for(int i=0;i<r.size();i++){
//		cout<<a[i];
//	}
	for(int i=0;i<n;i++){
		res=res+a[i]*x;
		x=x*10;
	}
	cout<<res;
}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
