#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> mia;
priority_queue<int,vector<int>,greater<int>> mib;
priority_queue<int,vector<int>,greater<int>> mic;


int n, ans=0;
int an=0, bn=0, cn=0, mxn;

struct club{
int a;
int b;
int c;
};
club C[100010];

void init(){
cin>>n;
mxn=n/2;
for(int i=1;i<=n;i++){
cin>>C[i].a>>C[i].b>>C[i].c;
}

}//

void t(int max,int sec,int thr,char num1,char num2,char num3){

if(num1=='a'){if(an<mxn){ans+=thr;mia.push(thr);an++;}
else{
   if(thr>mia.top()){ans+=thr-mia.top();mia.pop();mia.push(thr);}
	}
}

if(num1=='b'){if(bn<mxn){ans+=thr;mib.push(thr);bn++;}
else{
    if(thr>mib.top()){thr+=max-mib.top();mib.pop();mib.push(thr);}
	}
}
if(num1=='c'){if(cn<mxn){ans+=thr;mic.push(thr);cn++;}
else{
    if(thr>mic.top()){ans+=thr-mic.top();mic.pop();mic.push(thr);}
	}
}
return;
}

void s(int max,int sec,int thr,char num1,char num2,char num3){

if(num2=='a'){if(an<mxn){ans+=sec;mia.push(sec);an++;}
else{
   if(sec>mia.top()){ans+=sec-mia.top();mia.pop();mia.push(sec);}
      else{ t(max,sec,thr,num1,num2,num3);}
	}
}

if(num2=='b'){if(bn<mxn){ans+=sec;mib.push(sec);bn++;}
else{
    if(sec>mib.top()){ans+=sec-mib.top();mib.pop();mib.push(sec);}
      else{ t(max,sec,thr,num1,num2,num3);}
	}
}
if(num2=='c'){if(cn<mxn){ans+=sec;mic.push(sec);cn++;}
else{
    if(max>mic.top()){ans+=sec-mic.top();mic.pop();mic.push(sec);}
     else{ t(max,sec,thr,num1,num2,num3);}
	}
}
return;
}

void F(int max,int sec,int thr,char num1,char num2,char num3){

if(num1=='a'){if(an<mxn){ans+=max;mia.push(max);an++;}
else{
   if(max>mia.top()){ans+=max-mia.top();mia.pop();mia.push(max);}
      else{ s(max,sec,thr,num1,num2,num3);}
	}
}

if(num1=='b'){if(bn<mxn){ans+=max;mib.push(max);bn++;}
else{
    if(max>mib.top()){ans+=max-mib.top();mib.pop();mib.push(max);}
      else{ s(max,sec,thr,num1,num2,num3);}
	}
}
if(num1=='c'){if(cn<mxn){ans+=max;mic.push(max);cn++;}
else{
    if(max>mic.top()){ans+=max-mic.top();mic.pop();mic.push(max);}
     else{ s(max,sec,thr,num1,num2,num3);}
	}
}
return;
}

void clear_1(){
while(!mia.empty()){mia.pop();}
}
void clear_2(){
while(!mib.empty()){mib.pop();}
}
void clear_3(){
while(!mic.empty()){mic.pop();}
}

void solve(int a,int b,int c){
//cout<<a<<b<<c<<endl;
int f,s,t;
if(a>=b&&a>=c) f=a;
if(b>=a&&b>=c) f=b;
if(c>=a&&c>=b) f=c;

if(f!=a&&c!=f){if(a>=c){s=a;t=c;}else{s=c;t=a;}};//f=b 
if(f!=a&&b!=f){if(a>=b){s=a;t=b;}else{s=b;t=a;}};//f=c
if(f!=b&&c!=f){if(b>=c){s=b;t=c;}else{s=c;t=b;}};//f=a
//cout<<"F="<<f<<"S="<<s<<"T="<<t<<endl;

if(f==a&&s==b) F(a,b,c,'a','b','c');
if(f==a&&s==c) F(a,c,b,'a','c','b');
if(f==b&&s==a) F(b,a,c,'b','a','c');
if(f==b&&s==c) F(b,c,a,'b','c','a');
if(f==c&&s==b) F(c,b,a,'c','b','a');
if(f==c&&s==a) F(c,a,b,'c','a','b');

}//

void now(){
for(int i=1;i<=n;i++){
//cout<<"now="<<i<<endl;
solve(C[i].a,C[i].b,C[i].c);
}
}//

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int T;
cin>>T;
while(T--){
init();
now();
cout<<ans<<endl;
clear_1();
clear_2();
clear_3();
an=0;
bn=0;
cn=0;
ans=0;
}
}


//sort(C+1,C+1+n,cmp);
//for(int i=1;i<=n;i++){
//cout<<C[i].a;
//}
//int cmp(club&a,club&b){
//return a.a<b.a;
//}
