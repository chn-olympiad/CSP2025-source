#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct club{
	int a1,a2,a3;
}arr[MAXN],c1[MAXN],c2[MAXN],c3[MAXN];
bool step1(club a,club b){
	a.a1>b.a1;
}
bool step2(club a,club b){
	a.a2>b.a2;
}

bool step3(club a,club b){
	return a.a3>b.a3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ic1=0,ic2=0,ic3=0,jc1=0,jc2=0,jc3=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i].a1>>arr[i].a2>>arr[i].a3;
			if(arr[i].a1>=arr[i].a2 && arr[i].a1>=arr[i].a3){
				c1[ic1].a1=arr[i].a1;
				c1[ic1].a2=arr[i].a2;
				c1[ic1].a3=arr[i].a3;
				ic1++;
				
			}
			else if(arr[i].a2>arr[i].a1 && arr[i].a2>=arr[i].a3){
				c2[ic2].a1=arr[i].a1;
				c2[ic2].a2=arr[i].a2;
				c2[ic2].a3=arr[i].a3;
				ic2++;
				
			}else{
				c3[ic3].a1=arr[i].a1;
				c3[ic3].a2=arr[i].a2;
				c3[ic3].a3=arr[i].a3;
				ic3++;				
			}
						
		}if(ic1>n/2){
			sort(c1,c1+ic1,step1);
			for(;jc1<ic1-n/2;jc1++){
				if(c1[jc1].a2>c1[jc1].a3 &&ic2+1<n/2){
					c2[ic2].a1=c1[jc1].a1;
					c2[ic2].a2=c1[jc1].a2;
					c2[ic2].a3=c1[jc1].a3;
					ic2++;	
									
				}else{
					c3[ic3].a1=c1[jc1].a1;
					c3[ic3].a2=c1[jc1].a2;
					c3[ic3].a3=c1[jc1].a3;
					ic3++;						
				}
			}
		}
		if(ic2>n/2){
			sort(c2,c2+ic2,step2);
			for(;jc2<ic2-n/2;jc2++){
				if(c2[jc2].a1>c2[jc2].a3 &&ic1+1<n/2){
					c1[ic1].a1=c2[jc2].a1;
					c1[ic1].a2=c2[jc2].a2;
					c1[ic1].a3=c2[jc2].a3;
					ic1++;	
									
				}else{
					c3[ic3].a1=c2[jc2].a1;
					c3[ic3].a2=c2[jc2].a2;
					c3[ic3].a3=c2[jc2].a3;
					ic3++;						
				}
			}
		}
		if(ic3>n/2){
			sort(c3,c3+ic3,step3);
			for(;jc3<ic3-n/2;jc3++){
				if(c3[jc3].a1>c3[jc3].a2 &&ic1+1<n/2){
					c1[ic1].a1=c3[jc3].a1;
					c1[ic1].a2=c3[jc3].a2;
					c1[ic1].a3=c3[jc3].a3;
					ic1++;	
									
				}else{
					c2[ic2].a1=c3[jc3].a1;
					c2[ic2].a2=c3[jc3].a2;
					c2[ic2].a3=c3[jc3].a3;
					ic2++;						
				}
			}
		}
		for(int i=jc1;i<ic1;i++)ans+=c1[i].a1;
		for(int i=jc2;i<ic2;i++)ans+=c2[i].a2;
		for(int i=jc3;i<ic3;i++)ans+=c3[i].a3;
		cout<<ans<<'\n';
	}
}
