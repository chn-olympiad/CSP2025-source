#include <cstdio>
#define isfileio 1
#define filename "employ"
#define method 1
#if isfileio
#define programmefilein fopen(filename ".in", "r")
#define programmefileout fopen(filename ".out", "w")
#else
#define programmefilein stdin
#define programmefileout stdout
#endif
class fastInputHelper{
	char buf[1048577], *cn, *bufend;
	FILE *file;
	inline int getchar(){
		return cn != bufend ? *cn++ :
			(bufend = buf + fread(cn = buf, sizeof(char), 1048576llu, file), cn != bufend) ?
			*cn++ : ~0;
	}
	public:
		fastInputHelper(): cn(buf), bufend(buf), file(programmefilein){}
		~fastInputHelper(){
			fclose(file);
		}
		template<typename digit_type>
		fastInputHelper &operator>>(digit_type &x){
			int c = getchar();
			x = 0;
			while (c < 48 || c > 57){
				c = getchar();
				if (c == ~0){
					return *this;
				}
			}
			while (c > 47 && c < 58){
				x = x * 10 + (c & 15);
				c = getchar();
			}
			return *this;
		}
		template<size_t N>
		fastInputHelper &readLongNumber(int (&x)[N]){
			int c = getchar(), len = 0;
			while (c ^ 48 && c ^ 49){
				c = getchar();
				if (c == ~0){
					return *this;
				}
			}
			while (c > 47 && c < 50){
				x[len++] = c & 1;
				c = getchar();
			}
			return *this;
		}
}fih;
class fastOutputHelper{
	char buf[1048577], *cn;
	const char *bufend;
	FILE *file;
	inline void putchar(int c){
		*cn++ = c;
		if (cn == bufend){
			fwrite(cn = buf, sizeof(char), 1048576llu, file);
		}
	}
	template<typename digit_type>
	void writedigit(const digit_type &x){
		if (x){
			writedigit(x / 10);
			putchar(x % 10 | 48);
		}
	}
	public:
		fastOutputHelper(): cn(buf), bufend(buf + 1048576llu), file(programmefileout){}
		~fastOutputHelper(){
			if (cn != buf){
				fwrite(buf, sizeof(char), cn - buf, file);
				cn = buf;
			}
			fclose(file);
		}
		template<typename digit_type>
		fastOutputHelper &operator<<(const digit_type &x){
			if (x > 0){
				writedigit(x / 10);
				putchar(x % 10 | 48);
			}
			else if(x == 0){
				putchar(48);
			}
			else{
				putchar('-');
				writedigit(-(x / 10));
				putchar(-(x % 10) | 48);
			}
			return *this;
		}
		inline fastOutputHelper &putc(int c){
			putchar(c);
		}
}foh;
#if method == 1
int s[501], c[501], f[501], n, m, mo, pass, ans;
void dfs(int now, int runaway){
	if (runaway > m){
		return;
	}
	if (now == n){
		if (++ans == 998244353){
			ans = 0;
		}
		return;
	}
	if (now == mo + runaway){
		unsigned long long k = n - now, x = 1llu;
		while (k){
			x = x * k-- % 998244353llu;
		}
		ans += x;
		if (ans >= 998244353){
			ans -= 998244353;
		}
		return;
	}
	if (!s[now++]){
		if (++runaway > m){
			return;
		}
		for (int i = 0; i < n; ++i){
			if (!f[i]){
				f[i] = 1;
				dfs(now, runaway);
				f[i] = 0;
			}
		}
	}
	else for(int i = 0; i < n; ++i){
		if (f[i]){
			continue;
		}
		f[i] = 1;
		dfs(now, c[i] > runaway ? runaway : runaway + 1);
		f[i] = 0;
	}
}
int main(){
	fih >> n >> mo;
	fih.readLongNumber(s);
	for (int i = 0; i < n; ++i){
		fih >> c[i];
		pass += s[i];
		if (!c[i]){
			--pass;
		}
	}
	if (pass == n){
		unsigned long long x = 1llu;
		while (n){
			x = x * n-- % 998244353llu;
		}
		foh << x;
		return 0;
	}
	if (pass < mo){
		foh << 0;
		return 0;
	}
	m = n - mo;
	dfs(0, 0);
	foh << ans;
	return 0;
}
#endif
