#include<bits/stdc++.h>
using namespace std;
int t;
struct club{
	int num,a,ren;
	bool pp;
};
bool cmp(club n,club m){
	return n.a>m.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int loves[100005];
	for(int j=1;j<=t;j++){
		int n;cin>>n;
		club b[100005];
		for(int o=0;o<n;o++){
			for(int i=1;i<=3;i++){
				cin>>b[i+o*3].a;
				b[i+o*3].ren=o+1;
				b[i+o*3].pp=true;
				if((i+o*3)%3==1){
					b[i+o*3].num=1;
				}
				else if(i%3==2){
					b[i+o*3].num=2;
				}
				else{
					b[i+o*3].num=3;
				}
						
			}		
		}

		

		sort(b+1,b+n*3+1,cmp);
		int a1=0,a2=0,a3=0,count=0,all=n/2;
		for(int o=0;o<n;o++){
			for(int i=1;i<=3;i++){
				if(a1+a2+a3==n){
					break;
				}
			if(b[i+o*3].num==1&&a1<all&&b[i+o*3].pp==true){
				count+=b[i+o*3].a;
				a1++;
				for(int g=1;g<=n*3;g++){
					if(b[g].ren==b[i+o*3].ren){
						b[g].pp=false;
					}
					
				}
			}
			else if(b[i+o*3].num==2&&a2<all&&b[i+o*3].pp==true){
				count+=b[i+o*3].a;
				a2++;
				for(int g=1;g<=n*3;g++){
					if(b[g].ren==b[i+o*3].ren){
						b[g].pp=false;
					}
					
				}
			}
			else if(b[i+o*3].num==3&&a3<all&&b[i+o*3].pp==true){
				count+=b[i+o*3].a;
				a3++;
				for(int g=1;g<=n*3;g++){
					if(b[g].ren==b[i+o*3].ren){
						b[g].pp=false;
					}
					
				}
			}			
		}		

	}
			loves[j]=count;
		

	}
		
	for(int i=1;i<=t;i++){
		cout<<loves[i]<<"\n";
	}
	return 0;
} 
