#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c,choise;
	int cha;
}a[100100];
bool top(club c,club b){
	return c.cha<b.cha;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,s=0,b[4]={0};
        cin>>n;
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c); 
			if(a[j].a>=a[j].b){
				if(a[j].c>a[j].a){
					a[j].choise=3;
					a[j].cha=a[j].c-a[j].a;
					b[3]++;
					s+=a[j].c;
				}else{
					a[j].choise=1;
					b[1]++;
					s+=a[j].a;
					if(a[j].b>=a[j].c){
						a[j].cha=a[j].a-a[j].b;
					}else{
						a[j].cha=a[j].a-a[j].c;
					}
					
				}
			}else{
				if(a[j].c>a[j].b){
					a[j].choise=3;
					a[j].cha=a[j].c-a[j].b;
					b[3]++;
					s+=a[j].c;
				}else{
					a[j].choise=2;
					b[2]++;
					s+=a[j].b;
					if(a[j].a>=a[j].c){
						a[j].cha=a[j].b-a[j].a;
					}else{
						a[j].cha=a[j].b-a[j].c;
					}
				}
			}
			//cout<<a[j].cha<<endl;
        }
		if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
			cout<<s<<endl;
			continue;
		}
		//cout<<s<<endl;
        sort(a+1,a+1+n,top);
//        for(int j=1;j<=n;j++){
//        	cout<<a[j].cha<<' ';
//		}
//		cout<<endl;
        int max2=b[1];
        char max1=1;
        if(b[2]>max2){
        	max1=2;
        	max2=b[2];
		}
		if(b[3]>max2){
        	max1=3;
        	max2=b[3];
		}
		int j=1,k=1;
		while(k<=max2-n/2){
			if(a[j].choise==max1){
				k++;
				s-=a[j].cha;
			}
			j++;
			if(i==n)break;
		}
		cout<<s<<endl;
    }
    return 0;
}
