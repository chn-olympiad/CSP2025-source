#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('polygon.in','r',stdin);
	freopen('polygon.out','w',stdout);
	int n;
	cin>>n;
	int a[n];
	if(n<3){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	
		cout<<"0";
	}
	else if(n==3){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],a[2]))*2){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	else if(n==4){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],a[3]))*2){
			cout<<"0";
		}
	} 
	else if(n==5){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(a[4],a[3])))*2){
			cout<<"0";
		}
	} 
	else if(n==6){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(max(a[4],a[5]),a[3])))*2){
			cout<<"0";
		}
	} 
	else if(n==7){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(max(max(a[4],a[6]),a[5]),a[3])))*2){
			cout<<"0";
		}
	} 
	else if(n==8){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(max(max(max(a[4],a[7]),a[6]),a[5]),a[3])))*2){
			cout<<"0";
		}
	} 
	else if(n==9){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(max(max(max(max(a[4],a[8]),a[7]),a[6]),a[5]),a[3])))*2){
			cout<<"0";
		}
	} 
	else if(n==10){
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum<=max(a[0],max(a[1],max(a[2],max(max(max(max(max(max(a[4],a[9]),a[8]),a[7]),a[6]),a[5]),a[3])))*2){
			cout<<"0";
		}
	} 
	return 0;
} 
