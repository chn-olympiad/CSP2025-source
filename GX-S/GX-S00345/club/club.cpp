#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1280000],b[1280000],c[1280000];
int one=0,two=0;
int _1[1280000],_2[1280000];
int f1=0,s2=0,t3=0;
int small(int x){
	int s,_s;
	if(x==1){
		s=a[_1[1]];
		for(int i=2;i<=f1;i++){
			if(s>a[_1[i]]){
				s=a[_1[i]];
				_s=_1[i];
			}
		}
	}if(x==2){
		s=b[_2[1]];
		for(int i=2;i<=s2;i++){
			if(s>b[_2[i]]){
				s=b[_2[i]];
				_s=_2[i];
			}
		}
	}
	return _s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		for(int k=1;k<=n;k++){
			cin >> a[i] >> b[i] >> c[i]; 
			if(a[i]>b[i]){
				f1++;
				_1[f1]=i;
				one++;
			}if(b[i]>a[i]){
				s2++;
				two++;
				_2[s2]=i;
			}
		}
	}
	int out;
	for(int i=1;i<=n;i++){
		if(one>n/2 && two <n/2){
			one++;
			two--;
			f1++;
			out=small(2);
			a[f1]=b[out];
			b[out]=0;
		}if(one<n/2 && two > n/2){
			two--;
			one++;
			s2++;
			out=small(1);
			b[s2]=a[out];
			a[out]=0;
		}if(one>n/2 && two>n/2){
			t3++;
			out=small(1);
			c[t3]=a[out];
			a[out]=0;
			t3++;
			small(2);
			c[t3]=b[out];
			b[out]=0;
		}
	}
	int he=0;
	for(int i=1;i<f1;i++) he+=a[_1[i]];
	for(int i=1;i<s2;i++) he+=b[_2[i]];
	for(int i=1;i<t3;i++) he+=c[t3]*10;
	cout << he;
	return 0;
}
