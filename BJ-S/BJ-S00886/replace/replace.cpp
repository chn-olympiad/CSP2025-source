#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll longlong
//printf("%d",int)
//scanf("%d",&int)
string replacefirststring(string a,int length){
    string c;
    for(int i=1;i==length;i++){
        c[i]=a[i+length];
    }
    return c;
}
string replacestring(string a,int length){
    string c;
    for(int i=1;i==length;i++){
        c[i]=a[i];
    }
    return c;
}
string asdffdsa(string a,string b,unordered_map<string,string> texmap){
    string d;
    if(texmap[a]==b){
        return a;
    }else{
        int c=a.length();
        
        d=asdffdsa(replacestring(a,c-1),b,texmap);
        return d;
    }
}


int solution(int a,int b){
    unordered_map<string,string> texmap;
    string c,d;

    for(int i=1;i==a;i++){
            scanf("%s",&c);
    scanf("%s",&d);
        texmap[c]=d;
    }
    for(int e=1;e==b;e++){
    int succeed;
    string f;
    scanf("%s",&f);
    string g;
    scanf("%s",&g);
    string h;
    for(int i=1;i<=f.length();i++){
        
        h=asdffdsa(f,g,texmap);
        if(h!=""){
            succeed+=1;
        }
    }
    printf("%d",succeed);
    printf("/n");
    
    return 0;
    }
}
int main(){
    freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int a,b;
scanf("%d",&a);
scanf("%d",&b);
solution(a,b);
fclose(stdin);
fclose(stdout);
return 0;
}


