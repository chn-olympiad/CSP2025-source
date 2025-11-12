#include<bits/stdc++.h>
using namespace std;
bool sss(int x,int c){
    return 	x>c;
}
void zuowei(int lie,int hang,int w){
	int h=0;
	int l=1;
	int shu=0;
    for(int i=0;i<hang*lie;i++){
		shu++;
	    h++;
	    //cout<<l<<h;
	    if(h==hang){
			
			for(int j=0;j<=hang;j++){
				shu++;
				//l++;
				//i++;
				if(j>0) l++;
				//cout<<l<<" "<<h;
				if(j!=0) h--; 
				if(h==0){
				    l++;
				    break;	
				}
				if(shu==w){
					cout<<l<<" "<<h;
					return;
				}	
				
			}
		}
		if(shu==w){
		    cout<<l<<" "<<h;
		    break;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t=0;
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int a[z+1];
	for(int i=1;i<=z;i++){
	    cin>>a[i];	
	}
	t+=a[1];
	sort(a,a+z+1,sss);
	for(int i=1;i<=z;i++){
		if(a[i]==t){
			zuowei(m,n,i);
		}	
	}
	return 0;
}
