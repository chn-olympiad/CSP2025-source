#include<bits/stdc++.h>
using namespace std;

struct c_n{
	
	int a_1;//bu meng 1
	int a_2;//-- ---- 2
	int a_3;//-- ---- 3
	
}a[100002];

int max_1(int x,int y){
	
	if(x>=y) return x;
	else return y;

}

bool max_2(int x,int y){
	
	if(x>=y) return 1;
	else return 0;

}

int main(){
	
	freopen("club.in","r",stdin);//read
	freopen("club.out","w",stdout);//write
	
	int t,x;//time,di x ci
	int n,i;//nember,di i ren
	
	cin>>t;
	for(x=1;x<=t;x++){
		
		int d1=0,d2=0,d3=0;
		int s=0;
		
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i].a_1>>a[i].a_2>>a[i].a_3;
		}
		
		for(i=1;i<=n;i++){
			if(max_2(a[i].a_1,max_1(a[i].a_2,a[i].a_3))){
				if(d1>n/2){
					if(max_2(a[i].a_2,a[i].a_3)){
						if(d2>n/2){
							s=s+a[i].a_3;
							d3++;
						}	
						else{
							s=s+a[i].a_2;
							d2++;
						}
					}
					else{
						s=s+a[i].a_3;
						d1++;
					}
				}
				else{
					s=s+a[i].a_1;
					d1++;
				}
			}
			else{
				if(max_2(a[i].a_2,a[i].a_3)){
					if(d2>n/2){
						s=s+a[i].a_3;
						d3++;
					}
					else{
						s=s+a[i].a_2;
						d2++;
					}
				}
				else{
					s=s+a[i].a_3;
					d3++;
				}
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}
