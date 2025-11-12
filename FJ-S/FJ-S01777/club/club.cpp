#include<bits/stdc++.h>
using namespace std;
/*
这TM是啥
 

1.分配：把所有的满意度的人分到对应的上面 
2.超出处理：检查所有的人，辨别是不是移除后减少的最小的
3.calc 
4.我意识到要写vector 


*/
int T;
 
#define ll long long
ll n;
int fn=1,sn=1,tn=1;
struct Peo{
	int a,b,c;
}a[10010];
vector<Peo> f,s,t; 
bool cmp1(Peo a,Peo b){
	if(0-a.a+a.b>0-b.a+b.b){
		return false;
	}else{
		return true;
	}


}
bool cmp2(Peo a,Peo b){
	if(0-a.b+a.c>0-b.b+b.c){
		return false;
	}else{
		return true;
	}


}
bool cmp3(Peo a,Peo b){
	if(0-a.c+a.a>0-b.c+b.a){
		return false;
	}else{
		return true;
	}


}
signed main() {
freopen("club.in","r",stdin);

freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>T;
	while(T--){
		//cout<<"TEST"<<T<<endl;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				f.push_back(a[i]);
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				s.push_back(a[i]);
			}else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
				t.push_back(a[i]);
			}
		}//存储
		if(n==2){
		Peo x=a[1],y=a[2];
		int aa,bb,cc;
		aa=max(x.a+y.b,x.b+y.a);
		bb=max(x.b+y.c,x.c+y.b);
		cc=max(x.c+y.a,x.a+y.c);
		cout<<max(aa,max(bb,cc));
		continue;
		//试着骗个五分 
		
		}
		int cnt=0;
		ass:
		if(fn>n/2){
			/*
			比较的是(0-a+b/0-a+c) 
			sort一下 
			*/
			sort(f.begin(),f.end(),cmp1); 
			Peo temp=f[fn];
			fn--;
			sn++;
			f.pop_back();
			s.push_back(temp);
			
		} 
		if(sn>n/2){
			/*
			比较的是(0-b+c/0-b+a) 
			sort一下 
			*/
			sort(s.begin(),s.end(),cmp2); 
			Peo temp=s[fn];
			fn--;
			sn++;
			s.pop_back();
			t.push_back(temp);
			
		} 
		if(tn>n/2){
			/*
			比较的是(0-b+c/0-b+a) 
			sort一下 
			*/
			sort(t.begin(),t.end(),cmp3); 
			Peo temp=t[fn];
			fn--;
			sn++;
			t.pop_back();
			f.push_back(temp);
			
		} cnt++;
		if(cnt<=3) goto ass;
		
		int sum=0;
		for(int i=1;i<=fn;i++) {cout<<f[i].a<<" ";sum+=f[i].a;}
		cout<<endl;
		for(int i=1;i<=sn;i++) {cout<<s[i].b<<" ";sum+=s[i].b;}
		cout<<endl;
		for(int i=1;i<=tn;i++) {cout<<t[i].c<<" ";sum+=t[i].c;}
		cout<<endl;
		cout<<sum<<endl;
	}
    return 0;
}
