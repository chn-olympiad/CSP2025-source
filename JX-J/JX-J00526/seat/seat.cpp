#include <bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int isme;
	int all=n*m;
	for(int i=1;i<=all;i++){
		cin>>a[i];
	}
	isme=a[1];
	int weishu;
	sort(a+1,a+all+1);
	for(int i=1;i<=all;i++){
		if(a[i]==isme) {weishu=all-i+1;break;}
	}
	
	
	int lie;
	if(weishu%n==0){
		lie=(weishu/n);
	}else lie=(weishu/n)+1;
	cout<<lie<<" ";
	
	int hang;
	if(lie%2==0){
		if(weishu%n==0){
			 hang=1;
		 }
		 if(weishu%n==1){
			 hang=m;
		 }if(weishu%n==2){
			 hang=m-1;
		 }if(weishu%n==3){
			 hang=m-2;
		 }if(weishu%n==4){
			 hang=m-3;
		 }if(weishu%n==5){
			 hang=m-4;
		 }if(weishu%n==6){
			 hang=m-5;
		 }if(weishu%n==7){
			 hang=m-6;
		 }if(weishu%n==8){
			 hang=m-7;
		 }if(weishu%n==9){
			 hang=m-8;
		 }
		 
		 
	}
	if(lie%2!=0){
		if(weishu%n==0){
			 hang=m;
			 
		 }
		 if(weishu%n==1){
			 hang=1;
		 }if(weishu%n==2){
			 hang=2;
		 }if(weishu%n==3){
			 hang=3;
		 }if(weishu%n==4){
			 hang=4;
		 }if(weishu%n==5){
			 hang=5;
		 }if(weishu%n==6){
			 hang=6;
		 }if(weishu%n==7){
			 hang=7;
		 }if(weishu%n==8){
			 hang=8;
		 }if(weishu%n==9){
			 hang=9;
		 }
	}
	cout<<hang;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
