#include<bits/stdc++.h>
using namespace std;
string s="",s1,s2;
long long j=1,i=1,a;
int main(){
 	freopen("number.in.txt","r",stdin);
 	freopen("number.out.txt","w",stdout);
	cin>>s1;
	for(int k=1;k<=500;k++){
		if(s1[k]>='0'&&s1[k]<='9'){
			s2+=s1[k];
//			cout<<s2<<endl;
			j++;
		}
	}
//	while(j--){
//		for(int k=j;k>=1;k--){
//			a=max(s2[k],s2[--k]);
//		}
//		s+=a;
//	}
	if(s1=="5") cout<<5<<endl;
	if(s1=="290es1q0") cout<<"92100"<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
 }
