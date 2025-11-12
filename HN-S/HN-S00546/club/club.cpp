#include<bits/stdc++.h>
using namespace std;

int t;

struct A{
	int ind;
	int k;
};
A a1[100005];
A a2[100005];
A a3[100005];
bool isc[100005];

bool lst1(const A& x,const A& y){
	if (x.k>y.k){
		return true;
	}
	return false;
}
void run(){
	int n;
	int al[3] = {0,0,0};
	int res=0;
			
	cin>>n;
	for (int i=0;i<n;i++){
		a1[i].ind=i;
		a2[i].ind=i;
		a3[i].ind=i;
		cin>>a1[i].k>>a2[i].k>>a3[i].k;
		isc[i]=false;
	}
		
		
	sort(a1,a1+n,lst1);
	sort(a2,a2+n,lst1);
	sort(a3,a3+n,lst1);
		
	int turn[3];
		
	for(int i=0;i<n;i++){
		if (a1[i].k >=a2[i].k and a1[i].k >=a3[i].k){
			turn[0]=1;
			if (a2[i].k >=a3[i].k){
				turn[1]=2;
				turn[2]=3;
			}
			else{
				turn[2]=2;
				turn[1]=3;
			}
		}
		else if (a2[i].k >=a1[i].k and a2[i].k >=a3[i].k){
			turn[0]=2;
			if (a1[i].k >=a3[i].k){
				turn[1]=1;
				turn[2]=3;
			}
			else{
				turn[2]=1;
				turn[1]=3;
			}
		}
		else{
			turn[0]=3;
			if (a1[i].k >=a2[i].k){
				turn[1]=1;
				turn[2]=2;
			}
			else{
				turn[2]=1;
				turn[1]=2;
			}
		}
			
		for (int q=0;q<3;q++){
			if (turn[q]==1){
				if(!isc[a1[i].ind]){
					if(al[0]<=(n/2)-1){
						al[0]++;
						res+=a1[i].k;
						isc[a1[i].ind]=true;
					}
					
				}
			}
			else if(turn[q]==2){
				if(!isc[a2[i].ind]){
					if(al[1]<=(n/2)-1){
						al[1]++;
						res+=a2[i].k;
						isc[a2[i].ind]=true;
					}
				}
			}
			else{
				if(!isc[a3[i].ind]){
					if(al[2]<=(n/2)-1){
						al[2]++;
						res+=a3[i].k;
						isc[a3[i].ind]=true;
					}
					
				}
			}
		}
	}
	
	cout<<res<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int j=0;j<t;j++){
		run();
	}
		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
