#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	int ert;
	cin>>ert;
	int n[ert+1];
	long long  sum[ert+1];




	for(int i=0;i<=ert;i++){
        int x=0;
        int y=0;
        int z=0;
        int a[ert],b[ert],c[ert];
        num[i]=0;

		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a>>b>>c;
			if(a>=b&&a>c){
				if(x>=(n[i]/2)){
					if(b>c){
						y++;
						sum[i]+=b;
					}else if(b<c){
						z++;
						sum[i]+=c;
					}else if(y>z&&b==c){
						z++;
						sum[i]+=c;
					}else{
						y++;
						sum[i]+=b;
					}
				}else{
					x++;
					sum[i]+=a;
				}
			}
			if(b>=c&&b>a){
				if(y>=(n[i]/2)){
					if(a>c){
						x++;
						sum[i]+=a;
					}else if(a<c){
						z++;
						sum[i]+=c;
					}else if(x>z&&a==c){
						z++;
						sum[i]+=c;
					}else{
						x++;
						sum[i]+=a;
					}
				}else{
					y++;
					sum[i]+=b;
				}
			}
			if(c>=a&&c>b){
				if(z>=(n[i]/2)){
					if(a>b){
						x++;
						sum[i]+=a;
					}else if(a<b){
						y++;
						sum[i]+=b;
					}else if(y>x&&a==b){
						x++;
						sum[i]+=a;
					}else{
						y++;
						sum[i]+=b;
					}
				}else{
					z++;
					sum[i]+=c;
				}
			}
		}
		cout<<sum[i]<<endl;
	}








	fclose("stdin")
	fclose("stdout")
	return 0;
}
