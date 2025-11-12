#include<bits/stdc++.h>
using namespace std;
int yi(int a,int b){
	int c=0;
	vector<int> a1,b1;
	while(a!=0){
		a1.push_back(a%2);
		a/=2;
	}
	while(b!=0){
		b1.push_back(b%2);
		b/=2;
	}
	int la=a1.size(),lb=b1.size();
	if(la<=lb){
		for(int i=0;i<lb-la;i++) a1.push_back(0);
	}
	else for(int i=0;i<la-lb;i++) b1.push_back(0);
	for(int i=0;i<la;i++){
		if(b1[i]==a1[i]) c+=0;
		else c+=pow(2,i);
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	int a[n];
	vector<int> l,r;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i==j&&a[i]==k){
				l.push_back(i);
				r.push_back(j);
				s++;
			}
			else {
				int o=a[i];
				for(int p=i;p<j;p++){
					o=yi(o,a[p+1]);
				}
				cout<<o<<' ';
				if(o==k){
					l.push_back(i);
					r.push_back(j);
					s++;
				}
			}
		}
	}
	for(int i=0;i<s;i++){
		for(int j=i+1;j<s;j++){
			if(r[i]==-1||r[j]==-1) continue;
			else if(r[i]<l[j]) continue;
			else if(0==0){
				s--;
				r[j]=-1;
				l[j]=-1;	
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
