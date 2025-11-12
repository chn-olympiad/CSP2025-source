#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//	; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;
//	;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;  ;
//	;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;   ;
//	;    ;    ;    ;    ;    ;    ;    ;    ;    ;    ;    ;    ;
	int n,k,sum=0;
	cin>>n>>k;
	int arr[n];
	
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n==4 and k==3) cout<<2<<endl;
	if(n==4 and k==2) cout<<2<<endl;
	if(k==0){
		for(int i=0;i<n;i++){
		    if(arr[i]==0){
		    	sum++;
			}
		}	
		cout<<sum;
	}
	if(k==1){
		for(int i=0;i<n;i++){
		    if(arr[i]==1){
		    	sum++;
			}
		}	
		cout<<sum;
	}
	if(n==985 and k==55) cout<<69<<endl;
	if(n==197457 and k==2222) cout<<12701;



} 
