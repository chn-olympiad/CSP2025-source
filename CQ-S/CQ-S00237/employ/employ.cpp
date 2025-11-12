#include<bits/stdc++.h>
using namespace std;
int pp[505],nnx[505];
int a,b;
long long ans=0;
void baba(int ly,int fq,int l,int yj[]){
	if(ly+fq>=a) return;
//	cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=进入循环"<<endl;
	if(fq>=nnx[l]){
//		cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=失望循环开始"<<endl;
		for(int i=1;i<=a;i++){
			int fx=false;
			for(int j=1;j<l;j++){
				if(yj[j]==i){
					fx=true;
					break;
				}
			}
			if(fx==false) baba(ly,fq+1,i,yj+i);
		}
//		cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=失望循环结束"<<endl;
	}
	if(l==b){
//		cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=答案!"<<endl;
		ans++;
		return;
	}
	else{
//		cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环开始"<<endl;
		if(pp[l]==1){
//			cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 1 开始"<<endl;
			for(int i=1;i<=a;i++){
				int fx=false;
//				cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 1 主体开始"<<endl;
				for(int j=1;j<l;j++){
					if(yj[j]==i){
						fx=true;
						break;
					}
				}
//				cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 1 完成主体"<<endl;
				if(fx==false) baba(ly+1,fq,i,yj+i);
			}
//			cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 1 结束"<<endl;
		}
		else{
//			cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 2 开始"<<endl;
			for(int i=1;i<=a;i++){
				int fx=false;
//				cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 2 主体开始"<<endl;
				for(int j=1;j<l;j++){
//					cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 2 j="<<j<<endl;
					if(yj[j]==i){
						fx=true;
						break;
					}
				}
//				cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 2 完成主体"<<endl;
				if(fx==false) baba(ly,fq+1,i,yj+i);
			}
//			cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=比较循环 2 结束"<<endl;
		}
	}
//	cout<<"accent!ly="<<ly<<",fq="<<fq<<",l="<<l<<",trun=退出循环"<<endl;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	string q;
	cin>>q;
	int a1=true,n0=true,na0=false;
	for(int i=0;i<a;i++){
		if(q[i]=='0') a1=false;
		pp[i]=q[i]-'0';
	}
	for(int i=0;i<a;i++){
		cin>>nnx[i];
		if(nnx[i]==0) n0=false;
		if(nnx[i]!=0) na0=true;
	}
	if(a1==true){
		ans=1;
		for(int i=1;i<=q.size();i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(b==1){
		if(na0==true){
			cout<<0;
			return 0;
		}
		if(n0==true){
			ans=1;
			for(int i=1;i<=q.size();i++){
				ans=ans*i%998244353;
			}
			cout<<ans;
			return 0;
		}
	}
	baba(0,0,0,{});
	cout<<ans;
	return 0;
}

