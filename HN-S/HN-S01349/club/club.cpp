#include <bits/stdc++.h>
using namespace std;
int t,n,ab[100005][4],ans[4]={0},sum=0;
int bdx1(int a,int b,int c,int d){
	if     (max(max(a,b),c)==a){sum+=ab[d][1];return 1;}
	else if(max(max(a,b),c)==b){sum+=ab[d][2];return 2;}
	else if(max(max(a,b),c)==c){sum+=ab[d][3];return 3;}
}

/*
int bdx2(int a,int b,int c){
	if     (min(max(c,a),b)==a || min(max(b,a),c)==a){return 1;}    //c<a<b   min(max(c,a),b)==a  &&     b<a<c   min(max(b,a),c)==a   
	else if(min(max(c,b),a)==b || min(max(a,b),c)==b){return 2;}    //c<b<a   min(max(c,b),a)==b  &&     a<b<c   min(max(a,b),c)==b
	else if(min(max(a,c),b)==c || min(max(b,c),a)==c){return 3;}    //a<c<b   min(max(a,c),b)==c  &&     b<c<a   min(max(b,c),a)==c
}

int bdx3(int a,int b,int c){
	if     (min(min(c,a),b)==a){return 1;}      
	else if(min(min(c,b),a)==b){return 2;}    
	else if(min(min(a,c),b)==c){return 3;}    
}
*/

main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int xx=1;xx<=t;xx++){
    	//ÊäÈë 
    	cin>>n;
    	int max2_n=n/2;
    	
    	for(int i=1;i<=n;i++){
    		cin>>ab[i][1]>>ab[i][2]>>ab[i][3];
		}
		
		for(int i=1;i<=n;i++){
			ans[bdx1(ab[i][1],ab[i][2],ab[i][3],i)]++;
		}
		cout<<sum<<endl;
	}
	

	return 0;
}

