#include<bits/stdc++.h> 
using namespace std;
int n;
long long ans;

struct stu{
	int ax,ay,az;
	long long fc;
}a[200005];

int abb(int p){
	if(p<0)return -1*p;
	return p;
}

bool cmp(stu x,stu y){
	if(x.fc!=y.fc)return x.fc>y.fc;
	return(max(x.ax,x.ay)>max(y.ax,y.ay));
}

void solve(){
	ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].ax>>a[i].ay>>a[i].az;
		if(a[i].ax<=a[i].ay&&a[i].ax<=a[i].az){
			a[i].fc=abb(a[i].ay-a[i].az);
			a[i].ax=-1;
		}
		else if(a[i].ay<=a[i].ax&&a[i].ay<=a[i].az){
			a[i].fc=abb(a[i].ax-a[i].az);
			a[i].ay=-1;
		}
		else if(a[i].az<=a[i].ax&&a[i].az<=a[i].ay){
			a[i].fc=abb(a[i].ax-a[i].ay);
			a[i].az=-1;
		}
	}
	sort(a+0,a+n,cmp);
	
	int bx=0,by=0,bz=0;
	for(int i=0;i<n;i++){
		if(a[i].ax==-1){
			if(bz>=n/2||(a[i].ay>a[i].az&&by<n/2)){
				by++;
				ans+=a[i].ay;
			}else{
				bz++;
				ans+=a[i].az;
			}
		}
		else if(a[i].ay==-1){
			if(bz>=n/2||(a[i].ax>a[i].az&&bx<n/2)){
				bx++;
				ans+=a[i].ax;
			}else{
				bz++;
				ans+=a[i].az;
			}
		}
		else if(a[i].az==-1){
			if(by>=n/2||(a[i].ax>a[i].ay&&bx<n/2)){
				bx++;
				ans+=a[i].ax;
			}else{
				by++;
				ans+=a[i].ay;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
