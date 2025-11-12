#include <bits/stdc++.h>;
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		vector <int> a1,a2,a3;
		int s=0,x,y,z;
		int d1=n/2,d2=n/2,d3=n/2;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			a1.push_back(x);
			a2.push_back(y);
			a3.push_back(z);
			if(a1[i]==0 && a2[i]==0){
			    s+=a3[i];
			    d3--;
			    a1.pop_back();
			    a2.pop_back();
			    a3.pop_back();
			}
			else if(a2[i]==0 && a3[i]==0){
			    s+=a1[i];
			    d1--;
			    a1.pop_back();
			    a2.pop_back();
			    a3.pop_back();
			}
			else if(a1[i]==0 && a3[i]==0){
			    s+=a2[i];
			    d2--;
			    a1.pop_back();
			    a2.pop_back();
			    a3.pop_back();
			}
			
		continue;
		}
		for(int i=0;i<n;i++){
			if(a3[i]==0 && a2[i]!=0 && a1[i]!=0){
			    if(a1[i]>a2[i]){
					s+=a1[i];
					d1--;
				}
				else if(a2[i]>a1[i]){
					s+=a2[i];
					d2--;
				}
			continue;
			}
			else if((a1[i]) && (a2[i]) && (a3[i])){
			    if((a1[i] > a2[i]) && (a2[i] > a3[i])){
					if(d1>0){
						s+=a1[i];
						d1--;
					}
					else if(d2>0){
						s+=a2[i];
						d2--;
					}
					else if(d3>0){
						s+=a3[i];
						d3--;
					}
					continue;
				}
				else if((a1[i] > a3[i]) && (a3[i] > a2[i])){
					if(d1>0){
						s+=a1[i];
						d1--;
					}
					else if(d3>0){
						s+=a3[i];
						d3--;
					}
					else if(d2>0){
						s+=a2[i];
						d2--;
					}
					continue;
				}
				else if((a2[i] > a1[i]) && (a1[i] > a3[i])){
					if(d2>0){
						s+=a2[i];
						d2--;
					}
					else if(d1>0){
						s+=a1[i];
						d1--;
					}
					else if(d3>0){
						s+=a3[i];
						d3--;
					}
					continue;
				}
				else if((a2[i] > a3[i]) && (a3[i] > a1[i])){
					if(d2>0){
						s+=a2[i];
						d2--;
					}
					else if(d3>0){
						s+=a3[i];
						d3--;
					}
					else if(d1>0){
						s+=a1[i];
						d1--;
					}
					continue;
				}
				else if((a3[i] > a1[i]) && (a1[i] > a2[i])){
					if(d3>0){
						s+=a3[i];
						d3--;
					}
					else if(d1>0){
						s+=a1[i];
						d1--;
					}
					else if(d2>0){
						s+=a2[i];
						d2--;
					}
					continue;
				}
				else if((a3[i] > a2[i]) && (a2[i] > a1[i])){
					if(d3>0){
						s+=a3[i];
						d3--;
					}
					else if(d2>0){
						s+=a2[i];
						d2--;
					}
					else if(d1>0){
						s+=a1[i];
						d1--;
					}
					continue;
				}
				
			}
			else continue;
		}
		cout<<s<<endl;
	}
	
	

	return 0;
}
