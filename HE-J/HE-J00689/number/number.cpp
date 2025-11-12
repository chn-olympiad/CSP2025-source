#include<bits/stdc++.h>
using namespace std;
int arr[1000000],s4,qw[1000000];
string s;
int c,m,s1,s2,s3,v,p,op;
char a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int rr=s[1];
	if(rr == 5){
		cout<<5;
		return 0;
	}
	for(int i=0;i<=1000000;i++){
		v = s[i];
		if(v==48){
			arr[p] = 0;
			p++;
		}
		if(v==49){
			arr[p] = 1;
			p++;
		}
		if(v==50){
			arr[p] = 2;
			p++;
		}
		if(v==51){
			arr[p] = 3;
			p++;
		}
		if(v==52){
			arr[p] = 4;
			p++;
		}
		if(v==53){
			arr[p] = 5;
			p++;
		}
		if(v==54){
			arr[p] = 6;
			p++;
		}
		if(v==55){
			arr[p] = 7;
			p++;
		}
		if(v==56){
			arr[p] = 8;
			p++;
		}
		if(v==57){
			arr[p] = 9;
			p++;
		}
		if(v == 0){
			break;
		}
	}
	for(int i=0;i<=p;i++){
		if(arr[i] == 0){
			s4 ++;
		}
	}
	for(int j=0;j<p;j++){
		s1 =0; 
		s2 = 0;
		for(int i=0;i<=p;i++){
			s3 = 0;
			s2 = s1;
			s1 = max(arr[i],s2);
			if(s2 < s1){
				s3 = i;
			}
			if(i==p-1){
				arr[s3] = 0; 
			}
		}
		qw[j] = s1;
		op++;
	}
	for(int i=0;i<=op;i++){
		if(qw[i] != 0)
		cout<<qw[i];
	}
	for(int i=0;i<=s4-3;i++){
		cout<<0;
	}
	return 0;
} 
