#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct stu{
	int a1,a2,a3,a4,a5,a6,a7,a8;
}s[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
			}
			else if(a[i]==1&&a[i+1]==1){
				sum++;
				i++;
			}
		}
		cout<<sum;
	}
	else if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}
	else{
		int x1,x2,x3,x4,x5,x6,x7,x8;
		int t=k;
		x1=t%2;
		t/=2;
		x2=t%2;
		t/=2;
		x3=t%2;
		t/=2;
		x4=t%2;
		t/=2;
		x5=t%2;
		t/=2;
		x6=t%2;
		t/=2;
		x7=t%2;
		t/=2;
		x8=t%2;
		for(int i=1;i<=n;i++){
			int r=a[i];
			s[i].a1=r%2;
			r/=2;
			s[i].a2=r%2;
			r/=2;
			s[i].a3=r%2;
			r/=2;
			s[i].a4=r%2;
			r/=2;
			s[i].a5=r%2;
			r/=2;
			s[i].a6=r%2;
			r/=2;
			s[i].a7=r%2;
			r/=2;
			s[i].a8=r%2;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			int y1=s[i].a1,y2=s[i].a2,y3=s[i].a3,y4=s[i].a4,y5=s[i].a5,y6=s[i].a6,y7=s[i].a7,y8=s[i].a8;
			for(int j=i;j<=n;j++){
				if(j==i){
					if(x1==y1&&x2==y2&&x3==y3&&x4==y4&&x5==y5&&x6==y6&&x7==y7&&x8==y8){
						sum++;
						break;
					}
				}
				else{
					if(s[j].a1==y1){
						y1=0;
					}
					else{
						y1=1;
					}
					if(s[j].a2==y2){
						y2=0;
					}
					else{
						y2=1;
					}
					if(s[j].a3==y3){
						y3=0;
					}
					else{
						y3=1;
					}
					if(s[j].a4==y4){
						y4=0;
					}
					else{
						y4=1;
					}
					if(s[j].a5==y5){
						y5=0;
					}
					else{
						y5=1;
					}
					if(s[j].a6==y6){
						y6=0;
					}
					else{
						y6=1;
					}
					if(s[j].a7==y7){
						y7=0;
					}
					else{
						y7=1;
					}
					if(s[j].a8==y8){
						y8=0;
					}
					else{
						y8=1;
					}
					if(x1==y1&&x2==y2&&x3==y3&&x4==y4&&x5==y5&&x6==y6&&x7==y7&&x8==y8){
						sum++;
						i=j;
						break;
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}


