#include<bits/stdc++.h>
int gi(){
	char c;int x=0,f=0;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))x=(x*10)+(c^48),c=getchar();
	return f?-x:x;
}
std::mt19937 rnd(std::random_device{}());
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end() 
#define mem(x,w) memest(x,w,sizeof(x)) 
#define sz(x) (int)((x).size()) 
#define fi first
#define se second 
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
int main(){
	system("cd ~/HN-S00344/road");
	system("g++ -o gen gen.cpp -O2");
	system("g++ -o sol road.cpp -O2");
	system("g++ -o bf bf.cpp -O2");
	int t=0;
	while(1){
		system("./gen"),system("./sol"),system("./bf");
		if(system("diff -w road.out bf.out"))return puts("WA!!!"),0;
		std::cout<<++t<<": Accepted!!!\n";
	}
	return 0;
}

