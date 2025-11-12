#include<bits/stdc++.h>
using namespace;
int main(){

freopen("seat.in","r",stdin);
freopen("seat.cout","r",stdcout);
int a,b,c,d,e,f,g,h;
cin>>a>>b>>c>>d>>e>>f;
while{
    if(b-<0){
        a+1;
}
}
if(c>=d>=e>=f){
    cout<<"1 1";
}
if(d>=e>=f>=c){
    cout<<a<<b-1;
}
if(e>=f>=c>=d){
    cout<<a<<b-2;
}
if(f>=c>=d>=e){
    cout<<a<<b-3;
}

if(c>=e>=d>=f){
    cout<<"1 1";
}
if(e>=d>=f>=c){
    cout<<a<<b-1;
}
if(d>=f>=c>=e){
    cout<<a<<b-2;
}
if(f>=c>=e>=d){
    cout<<a<<b-3;
}

if(c>=e>=f>=d){
    cout<<"1 1";
}
if(e>=f>=d>=c){
    cout<<a<<b-1;
}
if(f>=d>=c>=e){
    cout<<a<<b-2;
}
if(d>=c>=e>=f){
    cout<<a<<b-3;
}

if(c>=f>=d>=e){
    cout<<"1 1";
}
if(f>=d>=e>=c){
    cout<<a<<b-1;
}
if(d>=e>=c>=f){
    cout<<a<<b-2;
}
if(e>=c>=f>=d){
    cout<<a<<b-3;
}
fclose(stdin);
fclose(stdcout);
    return 0;
}
